#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	int i=1,j=n;
	while(i<j&&i<=n&&j>0){
		int g=0;
		if(a[i]>=a[j]){
			while(a[i]>g&&i<j){
				if(g+a[j]<=a[i]){
					if(c[j]!=c[i])s+=a[j];
					if(g+a[j]==a[i])i++,j--,g=0;
					else g+=a[j],j--;
				}else{
					if(c[j]!=c[i])s+=a[i]-g;
					a[j]-=(a[i]-g);
					i++,g=0;
				}
			}
		}else{
			while(a[j]>g&&i<j){
				if(g+a[i]<=a[j]){
					if(c[i]!=c[j])s+=a[i];
					if(g+a[i]==a[j])j--,g=0,i++;
					else g+=a[i],i++;
				}else{
					if(c[j]!=c[i])s+=a[j]-g;
					a[i]-=(a[j]-g);
					j--,g=0;
				}
			}
		}
	}
	printf("%lld",s);

	return 0;
}
