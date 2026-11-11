#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
bool lin(string a){
	for(int i=0;i<=(a.size()-1)/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			return 0;
		}
	}
	return 1;
}
void tu(string a){
    for(int i=0;i<=(a.size()-1)/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			cnt++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char y;
		cin>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	if(lin(s)){
		cout<<"0";
		return 0;
	}
	tu(s);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
