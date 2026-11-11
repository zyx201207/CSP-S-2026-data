#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1005],ans[1005],bowl[1005],b[1005];
bool ss[1005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ss[i]=true;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long num=1;
	long long l=1;
	while(n--){
	for(int i=l;i<=n;i++){
		if(ans[a[i]]==0){
			b[num]=a[i];
			num++;
			ans[a[i]]++;
		}
		else{
		for(int i=l;i<=n;i++){
			if(b[i]==a[i]){
				b[i]=a[i];
			}
				for(int j=i;j<=n;j++){
					b[j]=0;
				}
		}
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			bowl[b[i]]++;
		}
	}
l++;
}
		for(int i=1;i<=n;i++){
			if(bowl[a[i]]!=0&&ss[a[i]]==true){
				cout<<bowl[a[i]]<<" ";
				ss[a[i]]=false;
			}
		}

		return 0;
}
