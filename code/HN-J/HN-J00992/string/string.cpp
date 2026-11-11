#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],ans;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0,j=n-1;i<=j;i++,j--){
		if(c[i]!=c[j]){
			int t=min(a[i],a[j]);
			if(t==a[j]){
				if(i+1==j) ans+=a[j];
				else ans+=a[i];
				int f=a[i]-a[j];
				while(f!=0){
					j--;
					if(i>=j)break;
					if(c[i]==c[j]&&a[j]<f)f-=a[j];
					else if(c[i]==c[j]&&a[j]>=f)a[j]-=f;
					if(a[j]>f)a[j]-=f;
					else f-=a[j];
				}
			}
			else{
				if(i+1==j) ans+=a[i];
				else ans+=a[j];
				int f=a[j]-a[i];
				while(f!=0){
					i++;
					if(i>=j)break;
					if(c[i]==c[j]&&a[i]<f)f-=a[i];
					else if(c[i]==c[j]&&a[i]>=f)a[i]-=f;
					if(a[i]>f)a[i]-=f;
					else f-=a[i];
				}
			}
		}
	}
	cout<<ans;
}

