#include<iostream>
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int cnt1=a[1],cnt2=0;
	char c1=c[1],c2=0;
	long long ans=0;
	int i=1,j=n;
	bool f=0;
	while(i<j){
		if(cnt1>0){
			if(a[j]<cnt1){
				cnt1-=a[j];
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				j--;
				f=0;
			}else{
				cnt2=a[j]-cnt1;
				if(c[i]!=c[j]){
					ans+=cnt1;
				}
				cnt1=0;
				i++;
				f=1;
			}
		}
		else if(cnt2>0){
			if(a[i]<cnt2){
				cnt2-=a[i];
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				i++;
				f=1;
			}else{
				cnt1=a[i]-cnt2;
				if(c[i]!=c[j]){
					ans+=cnt2;
				}
				cnt2=0;
				j--;
				f=0;
			}
		}
		else if(cnt1==0&&cnt2==0){
			if(f)cnt2=a[--j];
			else cnt1=a[++i];
		}
//		cout<<cnt1<<" "<<cnt2<<" "<<ans<<" "<<i<<" "<<j<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
//讨厌双指针qwq ，代码也太长了…… 
