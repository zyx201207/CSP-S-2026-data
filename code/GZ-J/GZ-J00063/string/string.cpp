//GZ-J00063 毕节七星关东辰实验学校 吴拼 
#include<iostream>
#include<string>
using namespace std;
struct kkk{
	int num;
	char c;
};
void solve(){
	int n;
	cin>>n;
	kkk a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	long long lsum=0,rsum=0,ans=0;
	int j=n;
	for(int i=1;i<=n;i++){
		if(i==j) break;
		lsum+=a[i].num;
		while(rsum<lsum){
			if(rsum+a[j].num>lsum){
				if(a[j].c!=a[i].c){
					ans+=lsum-rsum;
				}
				a[j].num=a[j].num-(lsum-rsum);
				rsum=lsum;
			}else{
				rsum+=a[j].num;
			    if(a[i].c!=a[j].c){
				    ans+=a[j].num;
			    }
			    j--;
			}
			//printf("%d\n",ans);
		}
		if(i==j) break;
	}
	printf("%lld",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
