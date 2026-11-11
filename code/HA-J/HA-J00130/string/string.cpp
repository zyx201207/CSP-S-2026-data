#include<bits/stdc++.h>
using namespace std;
int n,l=1,r;
struct str{
	char z;
	long long g;
}a[200005];
long long s;
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].g;
		cin>>a[i].z;
	}
	while(1){
		if(r-l==0)
		break;
		if(a[l].z==a[r].z)
		{	
			if(a[l].g>a[r].g){
				a[l].g-=a[r].g;
				r--;
			}else{
				if(a[l].g<a[r].g){
					a[r].g-=a[l].g;
					l++;
				}else{
					r--;
					l++;
				}
			}
		}else
		{
			if(a[l].g>a[r].g){
				s+=(a[l].g-a[r].g);
				a[l].g-=a[r].g;
				r--;
			}else{
				if(a[l].g<a[r].g){
					s+=(a[r].g-a[l].g);
					a[r].g-=a[l].g;
					l++;
				}else{
					s+=a[r].g;
					r--;
					l++;
				}
			}
		}
	}
	cout<<s;
	
	return 0;
}
