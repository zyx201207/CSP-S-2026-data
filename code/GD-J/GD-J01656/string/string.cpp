#include<bits/stdc++.h>
using namespace std;

string s=" ";
int sum;

void ans(){
	int len=s.size()-1;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]){
			sum++;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char ch;
		cin>>ch;
		for(int j=1;j<=x;j++){
			s=s+ch;
		}
	}
	
	ans();
	
	cout<<sum<<flush;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/

