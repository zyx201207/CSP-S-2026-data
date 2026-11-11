#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=1;
	cin>>n;
	int a[n+5];
	char l[n+5];
	bool p=true,bp=true;
	for (int i=0;i<n;i++){
		cin>>a[i]>>l[i];
	}
	for (int i=1;i<n;i++){
		if (l[i]==l[i-1]) sum++;
		else{
		    p=false;
		    break;
	    }
	    if (a[i]==a[i-1]);
	    else bp=false;
	}
	if (p){
		cout<<0;
	}
	else cout<<a[0]*3;
	return 0;
}
