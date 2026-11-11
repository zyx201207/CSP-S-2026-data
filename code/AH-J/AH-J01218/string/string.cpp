#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct stu{
	int s;
	char c;
}a[200050];   
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			sum+=min(a[l].s,a[r].s);
			if(a[l].s<a[r].s){
				a[r].s-=a[l].s;
				a[l].s=0;
				l++;
			}
			else if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				a[r].s=0;
				r--;
			}
			else{
				a[r].s=0,a[l].s=0;
				r--,l++;
			}
		}
		else{
			if(a[l].s<a[r].s){
				a[r].s-=a[l].s;
				a[l].s=0;
				l++;
			}
			else if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				a[r].s=0;
				r--;
			}
			else{
				a[r].s=0,a[l].s=0;
				r--,l++;
			}
		}
	}
	cout<<sum;
	return 0;
}
