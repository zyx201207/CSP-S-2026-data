#include<bits/stdc++.h>
using namespace std;
int n,a,k=0,cnt=-1;
	string c;
	long long l[100000001];
	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			l[k]=c[0]; 
			k++;
		}
	}
	for(int i=0;i<k;i++){
		if(l[i]!=l[k-i]){
			cnt++;
		}

	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
