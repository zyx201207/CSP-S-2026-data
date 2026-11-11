#include<bits/stdc++.h>
using namespace std;
long long n,a[200500],l,cnt;
char c[200500];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=0,r=0,j1=1,j2=n;
 	while(j1<j2){
		if(c[j1]==c[j2]){
			if(a[j1]-l>a[j2]-r){
				l=l+a[j2]-r;
				r=0;
				j2--;
			}else if(a[j1]-l<a[j2]-r){
				r=r+a[j1]-l;
				l=0;
				j1++;
			}else{
				l=0;
				r=0;
				j1++;
				j2--;
			}
		}else{
			if(a[j1]-l>a[j2]-r){
				l=l+a[j2]-r;
				cnt+=(a[j2]-r);
				r=0;
				j2--;
			}else if(a[j1]-l<a[j2]-r){
				r=r+a[j1]-l;
				cnt+=(a[j1]-l);
				l=0;
				j1++;
			}else{
				cnt+=(a[j1]-l);
				l=0;
				r=0;
				j1++;
				j2--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
