//GZ-J00174 ºúî£³¿
#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct node{
	long long len;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	long long l=1,r=n;
	while(l<r){
		if (a[l].len<a[r].len){
			if (a[l].c!=a[r].c){
				sum+=a[l].len;
			}
			a[r].len-=a[l].len;
			l++;
		}
		else if (a[l].len>a[r].len){
			if (a[l].c!=a[r].c){
				sum+=a[r].len;
			}
			a[l].len-=a[r].len;
			r--;
		}
		else{
			if (a[l].c!=a[r].c){
				sum+=a[l].len;
			}
			l++,r--;
		}
	}
	cout<<sum;
	return 0;
}
