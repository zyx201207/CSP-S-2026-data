#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c,s=0,chu;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c=m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(c<=0){
			break;
		}
		for(int j=i+1;j<=n;j++){
			if(c<=0){
				break;
			}
			if(a[i]==a[j]){
				i++;
			}
			else{
				if(c<=0){
					break;
				}
				else{
					if(j!=2){
						if(c<=0){
							break;
						}
						c=c-(a[j]-a[i])-(a[j]-a[j-2]);
						a[i]=a[j];
						a[j-2]=a[j];
						i++;
					}
					else{
						c=c-(a[j]-a[i]);
						a[i]=a[j];
						i++;
					}
				}
			}
		}
	}
	chu=a[1];
	for(int i=2;i<=n;i++){
		if(a[1]==a[i]){
			s++;
		}
	}
	s++;
	cout<<s;
	return 0;
}
