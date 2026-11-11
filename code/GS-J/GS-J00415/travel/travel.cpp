#include<bits/stdc++.h>
using namespace std;
bool a[5]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cut=0;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		a[0]={1};
		for (int i=0;i<2;i++){
			if (s1[i]!=s2[i]){
				a[1]={0};
			}
			else{
				cut++;
				if (cut==2){
					a[1]={1};
					char n=s1[2],m=s2[2];
					if ((n=='F'&&m=='D')||(n=='D'&&m=='F')){
						a[3]={1};
						a[2]={1};
					}
					if ((n=='A'&&m=='B')||(n=='B'&&m=='A')){
						a[3]={1};
						a[2]={1};
					}
					if ((n=='B'&&m=='C')||(n=='C'&&m=='B')){
						a[3]={1};
						a[2]={1};
					}
					if ((n=='A'&&m=='C')||(n=='C'&&m=='A')){
						a[3]={0};
						a[2]={1};
					}
				}
			}
		}
		
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
	return 0; 
}
