#include<bits/stdc++.h>
using namespace std;
string a; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ÊäÈë 
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int l;
		char c;
		cin>>l;
		cin>>c;
		for(int j=0;j<l;j++){
			//a[j]=c;
			a.push_back(c);
		}
	}
	//±éÀú 
	int cnt=0;
	for(int i=0;i<(a.length()+1)/2;i++){
		if(a[i]!=a[a.length()-1-i]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
