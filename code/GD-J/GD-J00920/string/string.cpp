#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2*1e5+5;
struct Node{
	int ai;
	char ci;
};
Node pr[MAXN];
Node wq[MAXN];
int n;
long long sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//记得删除批注！！！ 删除其余文件 ！！！ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pr[i].ai>>pr[i].ci;
		wq[n-i+1].ai=pr[i].ai;
		wq[n-i+1].ci=pr[i].ci;
		sum+=pr[i].ai;
	}
	sum=sum/2;
	long long prsum=pr[1].ai,wqsum=wq[1].ai;
	long long fisum=0;
	int i=1,j=1;
	long long ans=0;
	while(fisum<sum){
		if(pr[i].ci==wq[j].ci){
			if(prsum<wqsum){
				fisum=prsum;
				i++;
				prsum+=pr[i].ai;
			}else{
				if(prsum==wqsum){
					fisum=prsum;
					i++;
					prsum+=pr[i].ai;
					j++;
					wqsum+=wq[j].ai;
				}else{
					fisum=wqsum;
					j++;
					wqsum+=wq[j].ai;
				}
			}
		}else{
			if(prsum<wqsum){
				ans+=prsum-fisum;
				fisum=prsum;
				//cout<<"ans:"<<ans<<"fisum:"<<fisum<<endl;
				i++;
				prsum+=pr[i].ai;
			}else{
				if(prsum==wqsum){
					ans+=prsum-fisum;
					fisum=prsum;
					//cout<<"ans:"<<ans<<"fisum:"<<fisum<<endl;
					i++;
					prsum+=pr[i].ai;
					j++;
					wqsum+=wq[j].ai;
				}else{
					ans+=wqsum-fisum;
					fisum=wqsum;
					//cout<<"ans:"<<ans<<"fisum:"<<fisum<<endl;
					j++;
					wqsum+=wq[j].ai;
				}
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}
