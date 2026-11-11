#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char> s;
	int n;
	cin>>n;
	while(n){
		int a;
		char c;
		cin>>a>>c;	
		for(int i=0;i<a;i++){
			s.push_back(c);
		}
		n--;
	}
	int time=0;
	int k=s.size();
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-i-1]){
			time++;
		}
	}
	cout <<time;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
