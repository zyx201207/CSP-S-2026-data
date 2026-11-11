//GZ-J00384 Îºð©éª
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+50;
int n,sumn=0,cnt=0;
string s;
struct node{
	long long number;
	char zifu;
}q[N];

int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>q[i].number>>q[i].zifu;
		sumn+=q[i].number;
		for (int j=1;j<=q[i].number;j++) s+=q[i].zifu;
	}

	int k=0;
	if(sumn%2==1){
		for (int i=sumn/2+1;i<=sumn-1;i++){
			if(s[i]!=s[k]) cnt++;
			k++;
		}
		k=0;
	}
	else{
		for (int i=sumn/2;i<=sumn-1;i++){
			if(s[i]!=s[k]) cnt++;
			k++;
		}
	}

	printf("%d",cnt);

	return 0;
}
