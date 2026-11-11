#include <bits/stdc++.h>
using namespace std;
int l,l1;
int a[200005];
int ans=0;
int an(int a,int b){
	int h=min(a,b),cnt=0;
	while(h>0){
		if(a%2==1&&b%2==1){
			cnt=cnt*2+1;
		}
		h/=2;
		a/=2;
		b/=2;
	}
	return cnt;
}

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","r",stdou);
	cin>>l>>l1;
	for (int i=0;i<l;i++){
		cin>>a[i];
	}
	int max=0;
	for (int i=0;i<l;i++){
		if (a[i]>max)max=a[i];
	}
	cout<<ans;
	return 0;
}
