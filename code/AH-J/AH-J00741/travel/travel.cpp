#include<bits/stdc++.h>
using namespace std;
char a[1000],a1[1000],b[1000],b1[1000];
int k=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a1>>b1;
    int a2=strlen(a),a3=strlen(a1),b2=strlen(a),b3=strlen(a);
    for(int i=0;i<a2;i++){
    if(a[i]==a1[i])k++;
    }
    if(k==a2){
    cout<<1;
    if(b[0]==b1[0]&&b[1]==b1[1]){
    	cout<<1;
		if(b[2]>='A'&&b[2]<='C'&&b1[2]<='C'&&b1[2]>='A'){
			cout<<1;
			if(b[2]==b1[2]-1&&b[2]!='C'){
				cout<<1;
			}
			else if(b[2]-1==b1[2]&&b1[2]!='C'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if(b[2]>='D'&&b[2]<='F'&&b1[2]<='F'&&b1[2]>='D'){
			cout<<1;
			if(b[2]==b1[2]-1&&b[2]!='C'){
				cout<<1;
			}
			else if(b[2]-1==b1[2]&&b1[2]!='C'){
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		cout<<"000";
		return 0;
	}
    }
    else{
    	cout<<"0000";
    	return 0;
	}
    return 0;
}
