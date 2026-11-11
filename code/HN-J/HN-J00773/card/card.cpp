#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[200005],h=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];
	if(i!=1&&a[i-1]==a[i])h++;
	else if(i!=1&&a[i]!=a[i-1]){if(h%2==0)cout<<h/2<<" ";
	else cout<<h/2+1<<" ";
	h=1;
	}
	}if(h%2==0)cout<<h/2<<" ";
	else cout<<h/2+1<<" ";
	return 0;
}
