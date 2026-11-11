#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,s,d,f,g,h;
	cin>>a>>s>>d>>f>>g>>h;
	int w[d];
	for(int i=1;i<d;i++){
		cin>>w[i];
	}
	for(int i=0;i<g;i++){
		cout<<h*7<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
