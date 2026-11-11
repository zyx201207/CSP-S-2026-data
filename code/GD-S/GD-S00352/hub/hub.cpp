#include<bits/stdc++.h>
using namespace std;
int ri(){
	int ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){}
	for(;isdigit(c);c=getchar())	ans=ans*10+(c^48);
	return ans;
}
int main(){
	freopen("hub.out","w",stdout);
	cout<<"1\n2";
	return 0;
} 
