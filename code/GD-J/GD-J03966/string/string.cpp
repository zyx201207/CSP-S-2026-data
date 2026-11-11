#include<bits/stdc++.h>
using namespace std;
long long n,m[1000000],l,r,s;
char a[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>m[i]>>a[i];
	r=n-1;
	while(l<r){
		if(a[l]==a[r]){
			if(m[l]>m[r]){
				m[l]-=m[r];
				r--;
			}
			else if(m[l]<m[r]){
				m[r]-=m[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(m[l]>m[r]){
				s+=m[r];
				m[l]-=m[r];
				r--;
			}
			else if(m[l]<m[r]){
				s+=m[l];
				m[r]-=m[l];
				l++;
			}
			else{
				s+=m[r];
				l++;
				r--;
			}
		}
	}
	cout<<s;
	return 0;
}
