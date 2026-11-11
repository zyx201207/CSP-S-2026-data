#include<bits/stdc++.h>
using namespace std;
int a,b,sss;
string q,w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		scanf("%d",&b);
		scanf("%s",&q);
		for(int j=0;j<b;j++){
			q+=w;
		}
	}
	for(int i=0;i<a;i++){
		if(q[a-i-1]!=q[i]){
			sss++;
		}
	}
	printf("%d",sss);
	return 0;
}

//给点分吧，超时乃c++常事。 
