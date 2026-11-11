#include<bits/stdc++.h>
using namespace std;
char a1[10],b1[10],a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++) cin>>a1[i];
	cin>>a2;
	for(int i=1;i<=4;i++) cin>>b1[i];
	cin>>b2;
	if(a1[1]==b1[1] && a1[2]==b1[2]){
		cout<<1;
		if(a1[3]==b1[3] && a1[4]==b1[4]){
		cout<<1;
		    if(a2<='E' && b2<='E' || a2>='C' && b2>='C'){
		        cout<<1;
		        if(a2-b2==1 || b2-a2==1){
					cout<<1;
				}else{
					cout<<0;
				}
            }else{
				cout<<00;
			}
        }else{
			cout<<000;
		}
    }else{
		cout<<0000;
	}
    return 0;
}
