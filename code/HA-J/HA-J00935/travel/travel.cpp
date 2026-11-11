#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[10],b[10];
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<3;i++){
			a[i]=s1[i];
			b[i]=s2[i];
		}
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<"1";
			if(a[2]>=65&&a[2]<=67&&b[2]>=65&&b[2]<=67){
				cout<<"1";
				if(a[2]<b[2]){
					if(a[2]+1==b[2]){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
				if(a[2]>b[2]){
					if(a[2]-1==b[2]){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else if(a[2]>=68&&a[2]<=70&&b[2]>=68&&b[2]<=70){
				cout<<"1";
				if(a[2]<b[2]){
					if(a[2]+1==b[2]){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
				if(a[2]>b[2]){
					if(a[2]-1==b[2]){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
