#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long id;
	char zf;
}a[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].zf;
	}
	long long g=0;
    int l=1,r=n;
    while(l<=r){
    	if(a[l].zf==a[r].zf){
    		l++;
    		r--;
		}
    	if(a[l].zf!=a[r].zf){
    		if(a[l].id>a[r].id){
    			a[l].id-=a[r].id;
    			g+=a[r].id; 
    			r--;
			}
			else if(a[l].id<a[r].id){
				a[r].id-=a[l].id;
				g+=a[l].id;
				l++;
			}
		}
	}
	cout<<g;
	
	
}


