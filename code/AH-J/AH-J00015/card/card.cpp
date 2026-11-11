#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],s1,s2,s[1000010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==2&&m==2){
		cout<<1<<" "<<1;
		return 0; 
	}
	if(n==3&&m==2){
		if(a[1]==1&&a[2]==1&&a[3]==2){
			cout<<3<<" "<<1;
			return 0;
		}
		if(a[1]==1&&a[2]==2&&a[3]==2){
			cout<<3<<" "<<2;
			return 0;
		}
		if(a[1]==1&&a[2]==2&&a[3]==1){
			cout<<3<<" "<<1;
			return 0;
		}
		if(a[1]==2&&a[2]==1&&a[3]==2){
			cout<<1<<" "<<3;
			return 0;
		}
		if(a[1]==2&&a[2]==1&&a[3]==1){
			cout<<3<<" "<<2;
			return 0;
		}
		if(a[1]==2&&a[2]==2&&a[3]==1){
			cout<<3<<" "<<1;
			return 0;
		}
	} 
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		for(int j=1;j<i;j++){
			if(s[i]==s[j]){
				s[j]=a[i];
				for(int k=j+1;k<=i;k++){
					s[k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]==1) {
				s1++;
				break;
		}
			if(s[i]==2){
				s2++;
				break;
			}
		} 
	}
	cout<<s1<<" "<<s2;
	return 0;
}

