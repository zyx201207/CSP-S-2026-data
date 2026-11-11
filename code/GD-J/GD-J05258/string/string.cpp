#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50;
#define int long long
int sum,c,yu,n;
struct node{
	int a;
	char b;
}h[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i].a>>h[i].b;
		yu+=h[i].a%2;
	}
	int l=1,r=n;
	while(l<r){
			if(h[l].a>h[r].a){
				if(h[l].b==h[r].b){
					h[l].a-=h[r].a;
					r--;
				}
				else{
					sum+=h[r].a;
					h[l].a-=h[r].a;
					r--;
				}
				
			}
			else if(h[l].a==h[r].a){
					if(h[l].b==h[r].b){
					l++;
					r--;
				}
				else{
					sum+=h[r].a;
					l++;
					r--;
				}
			}
			else{
				if(h[l].b==h[r].b){
					h[r].a-=h[l].a;
					l++;
				}
				else{
					sum+=h[l].a;
					h[r].a-=h[l].a;
					l++;
				}
			}
			
		}
		cout<<sum;
}
