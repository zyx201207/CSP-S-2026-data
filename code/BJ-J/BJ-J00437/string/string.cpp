#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		len+=a[i];
		cin>>c[i];
	}
	long long summ=a[1];
	int lastid=n;
	long long ans=0;
	for(int i=1;i<=n;){
		if(c[i]==c[lastid]){
			if(a[i]>a[lastid]){
				a[i]-=a[lastid];
				a[lastid]=0;
				lastid--;
			}else if(a[i]==a[lastid]){
				a[lastid]=0;
				a[i]=0;
				i++;
				summ+=a[i];
				lastid--;
			}else{
				a[lastid]-=a[i];
				a[i]=0;
				i++;
				summ+=a[i];
			}
		}else{
			if(a[i]>a[lastid]){
				ans+=a[lastid];
				a[i]-=a[lastid];
				a[lastid]=0;
				lastid--;
			}else if(a[i]==a[lastid]){
				ans+=a[i];
				a[lastid]=0;
				a[i]=0;
				i++;
				summ+=a[i];
				lastid--;
			}else{
				ans+=a[i];
				a[lastid]-=a[i];
				a[i]=0;
				i++;
				summ+=a[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
