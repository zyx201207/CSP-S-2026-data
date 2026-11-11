#include<bits/stdc++.h>
using namespace std;
const int N=655360;
struct duan{
	int chang;
	char zimu;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].chang>>a[i].zimu;
	int l=1,r=n;
	long long count=0;
	while(l<r){
		if(a[l].zimu!=a[r].zimu){
			if(a[l].chang==a[r].chang){
				count+=a[r].chang;
				l++;
				r--;
			}
			else{
				if(a[l].chang>a[r].chang){
					count+=a[r].chang;
					a[l].chang-=a[r].chang;
					r--;
				}
				else{
					count+=a[l].chang;
					a[r].chang-=a[l].chang;
					l++;
				}
			}
		}
		else{
			if(a[l].chang==a[r].chang){
				l++;
				r--;
			}
			else{
				if(a[l].chang>a[r].chang){
					a[l].chang-=a[r].chang;
					r--;
				}
				else{
					a[r].chang-=a[l].chang;
					l++;
				}
			}
		}
	}
	cout<<count;
	return 0;
}
