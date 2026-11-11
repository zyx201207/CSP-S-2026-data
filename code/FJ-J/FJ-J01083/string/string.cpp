#include<bits/stdc++.h>
using namespace std;
char ch[200020];
int a[200020];
int l,r;
long long x;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	l=1;
	r=n;
	while(r>l){
		if(ch[l]==ch[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				
			}
			else if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
				
			}
		}
		else{
			if(a[l]>a[r]){
				x+=a[r];
				a[l]-=a[r];
				r--;
				
			}
			else if(a[l]==a[r]){
				x+=a[r];
				l++;
				r--;
			}
			else{
				x+=a[l];
				a[r]-=a[l];
				l++;
				
			}
		}
	}
	cout<<x;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
