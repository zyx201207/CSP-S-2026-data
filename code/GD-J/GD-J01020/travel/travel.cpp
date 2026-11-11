#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
		if(aa[1]==bb[1]&&aa[0]==bb[0]){
			cout<<1;
			if(aa[2]<='C'&&aa[2]>='A'){
				if(bb[2]>='A'&&bb[2]<='C'){
					cout<<1;
					if(max(aa[2],bb[2])-min(aa[2],bb[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0;
					cout<<0;
				}
			}
			else if(aa[2]<='F'&&aa[2]>='D'){
				if(bb[2]>='F'&&bb[2]<='D'){
					cout<<11;
				}
				else{
					cout<<0;
					cout<<0;
				}
			}
			else{cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
