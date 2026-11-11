#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
struct node{
	int a;
	string b;
}p[N];
int book[50],qpow[50];
int n,m,cnt,ans,flag;
bool cmp(node x,node y){
	return x.a<y.a;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	qpow[0]=1;
	for(int i=1;i<=31;++i) qpow[i]=2*qpow[i-1];
	for(int i=1;i<=n;++i){
		cin>>p[i].a;	
		int x=p[i].a;
		while(x){
			if(x&1){
				p[i].b='1'+p[i].b;
				book[32-p[i].b.size()]++;
			}else{
				p[i].b='0'+p[i].b;
			}x>>=1;
		}while(p[i].b.size()<=30){
			p[i].b='0'+p[i].b;
		}//cout<<p[i].b<<endl;
	}sort(p+1,p+1+n,cmp);
	cnt=1;
	for(int i=1;i<=31;++i){
		if(book[i]==m){
			ans+=qpow[31-i];
			flag=1;
		}
		if(book[i]>m){
			if(!flag){
				for(int j=cnt;j<=n;++j){
					if(p[j].b[i-1]=='0'){
						for(int k=0;k<=30;++k){
							if(p[j].b[k]=='1') book[k+1]--;
						}cnt=j;
					}
				}
			}ans+=qpow[31-i];
		}//for(int j=1;j<=31;++j){
		//	cout<<book[j]<<' ';
		//}cout<<endl;
	}cout<<ans;
	

	return 0;
}
