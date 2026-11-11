#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct node{
	long long x;
	char z;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].z;
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(a[i].x==a[j].x&&a[i].z==a[j].z){
			i++;
			j--;
		}
		else if(a[i].x<a[j].x&&a[i].z==a[j].z){
			a[j].x-=a[i].x;
			i++;
		}
		else if(a[i].x>a[j].x&&a[i].z==a[j].z){
			a[i].x-=a[j].x;
			j--;
		}
		else if(a[i].x==a[j].x&&a[i].z!=a[j].z){
			ans+=a[i].x;
			i++;
			j--; 
		}
		else{
			if(a[i].x<a[j].x){
				a[j].x-=a[i].x;
				ans+=a[i].x;
				i++;
			}
			else{
				a[i].x-=a[j].x;
				ans+=a[j].x;
				j--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 

