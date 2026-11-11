#include <bits/stdc++.h>
using namespace std;

struct s{
	int a;
	char c;
}sp[100010];

char k1[100000000];
char k2[100000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> sp[i].a >> sp[i].c;
		
	}

	long long k=0,v=0;
	for(int i=0;i<n;i++){
		while(sp[i].a--){
			k1[k]=sp[i].c;
			k++;
		}
	}
	for(long long i=k;i>=0;i--){
		k2[i]=k1[k-i];
		if(k2[i]!=k1[i]){
			v++;
		}
	}
	if(v==2){
		cout << 0;
	}
	else 
	cout << v/2;
	return 0;
}
