#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct hss{
	long long ak;
	char c;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i].ak>>a[i].c;
	}
	int l=1,r=n;
	unsigned long long sum=0;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].ak==a[r].ak){
				l++;
		    	r--;
		    	continue;
			}else{
				if(a[l].ak>a[r].ak){
					a[l].ak-=a[r].ak;
					r--;
				}else if(a[l].ak<a[r].ak){
					a[r].ak-=a[l].ak;
					l++;
				}
			}
		}else{
			if(a[l].ak==a[r].ak){
				sum+=a[l].ak;
				l++;
		    	r--;
		    	continue;
			}else{
				if(a[l].ak>a[r].ak){
					a[l].ak-=a[r].ak;
					sum+=a[r].ak;
					r--;
				}else if(a[l].ak<a[r].ak){
					a[r].ak-=a[l].ak;
					sum+=a[l].ak;
					l++;
				}
			}
		}
	} 
	cout<<sum;
	return 0;
} 

