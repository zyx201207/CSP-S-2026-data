//GZ-J00697 李昂泽 贵州师范大学附属中学
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else {
    	cout<<0<<0<<0<<0;
    	return 0;
	}
    bool f;
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]){
            f=true;
        }
        else{
           f=false;
        }
    }
    if(f) cout<<1;
    else cout<<0;
    if(f){
    	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
    		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
    			cout<<1;
			}
			else cout<<0;
		}
		else if(s1[2]=='C'||s1[2]=='D'){
			if(s2[2]=='C'||s2[2]=='D'){
				cout<<1;
			}
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
    if(s1[2]+1==s2[2]){
        if(s1[2]=='C'){
            if(s2[2]=='D'){
                cout<<0;
            }
        }
        else if(s2[2]=='C'){
            if(s1[2]=='D'){
                cout<<0;
            }
        }
        else cout<<1;
    }
    else cout<<0;
    return 0;
}

