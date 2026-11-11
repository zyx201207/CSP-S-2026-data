#include<bits/stdc++.h> 
using namespace std;
long long n,i,h=0,a[200005],l=0,r;
char q[200005];
string s;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>q[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(q[l]!=q[r]){
			h=h+min(a[l],a[r]);
			//需要将一边修改为另一边的样子 
		}
		if(a[l]>=a[r]){
			a[l]-=a[r];
			r--;
		}else{
			a[r]-=a[l];
			l++;
		}
		//对比过，修改过的就不用看了 
	}
	cout<<h;
	return 0;
}
