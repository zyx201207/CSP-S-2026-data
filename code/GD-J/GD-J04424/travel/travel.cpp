#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		if(s1[0]==s2[0]){
			if(s1[1]==s2[1]){
				a[2]=1;
				if(s1>s2){
					swap(s1,s2);
				}
				if(s1[2]=='C') a[3]=0;
				else{
					a[3]=1;
					if(s1[2]+1==s2[2]){
						a[4]=1;
					}
					else a[4]=0;
				}
			}
			else a[2]=0;
		}
		else a[2]=0;
	}
	else a[1]=0;
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}

