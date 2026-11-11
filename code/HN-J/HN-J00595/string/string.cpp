#include<bits/stdc++.h>
using namespace std;
int n;
long long zo=0;
int nu[200000];
char c[200000];
int use(long long t){
	int p=0;
	char g;
	long long h=t;
	for(int i=0;;i++){
		if(h<nu[i]){
			g=c[i];
			break;
		}
		h-=nu[i];
	}
	h=t;
	for(int i=n-1;;i--){
		if(h<nu[i]){
			p=i;
			break;
		}
		h-=nu[i];
	}
	if(g==c[p])return 0;
	return 1;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	long long he=0;
	for(int i=0;i<n;i++){
		cin>>nu[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		zo+=nu[i];
	}
	for(long long i=0;i<(zo/2)-1;i++){
		he+=use(i);
	}
	cout<<he;
	return 0;
}

