#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int L,n,ans=0;
	cin>>n;
	vector<char>l(n);
	vector<char>lswp(n);
	vector<int>num(n);
	vector<char>cha(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
		cin>>cha[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++){
			l[j]=cha[i];
		}
	}
	for(int i=0;i<n;i++){
		lswp[i]=l[n-1-i];
	}
	for(int i=0;i<n;i++){
		if(lswp[i]!=l[i]){
			ans+=1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
