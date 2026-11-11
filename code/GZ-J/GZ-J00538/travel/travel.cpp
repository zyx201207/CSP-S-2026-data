//GZ-J00538 遵义市汇川区周林学校 黎辰阳
#include<bits/stdc++.h>
using namespace std;
int a[4]= {0};
int main() {
	froepen("travel.in","r",stdin);
	froepen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		a[0] = 1;
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
			a[1] = 1;
			if(s1[2]!=s2[2]) {
				if(s1[2]<='C' && s2[2]<='C' || s1[2]>='D' && s2[2]>='D') {
					a[2] = 1;
					if(s1[2]=='D') {
						a[3] = 1;
					} 
					else if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) {
						a[3] = 1;
					} 
					else {
						for(int l=0; l<4; l++) {
							cout<<a[l];
						}
						return 0;
					}
				}

				else {
					for(int k=0; k<4; k++) {
						cout<<a[k];
					}
					return 0;
				}
			}

			else {
				for(int i=0; i<4; i++) {
					cout<<a[i];
				}
				return 0;
			}

		} 
		else {
			for(int j=0; j<4; j++) {
				cout<<a[j];
			}
			return 0;
		}
	}

	else {
		for(int i=0; i<4; i++) {
			cout<<a[i];
		}
		return 0;
	}

	for(int i=0; i<4; i++) {
		cout<<a[i];
	}

	return 0;
}

