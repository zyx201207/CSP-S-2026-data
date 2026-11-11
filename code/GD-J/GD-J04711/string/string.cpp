#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}ll i=1,j=n,l=a[1];
	while(i<j){
		if(c[i]==c[j]){
			if(l<a[j]){
				j++;
				i++;
				l=a[i];
			}else{
				l-=a[j];
			}
		}else{
			sum+=min(l,a[j]);
			if(l==a[j]){
				l=a[++i];
			}else if(l<a[j]){
			l=a[++i];
			j++;	
			}else{
				l-=a[j];
			}
		}
		j--;
	}cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
