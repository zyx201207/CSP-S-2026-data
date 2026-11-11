indeclube<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,s1;
    string a2,s2;
    cin>>a1;
    if(a1==s1){
    	cout <<"1";
	}
	else{
		cout <<"0";
	}
    for(int i=0;i<=2;i++){
       cin>>a2[i];
    }
    cin>>s1;
    for(int i=0;i<=2;i++){
        cin>>s2[i];
    }
    if(a1==s1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    for(int i=0;i<=1;i++){
        if(a2[i]==s2[i]){
            cout <<"1";
        }else{
            cout <<"0";
        }
    }
    if(a2[2]=='D'||a2[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
        cout<<"1";

    }else if(a2[2]!='D'||a2[2]!='F'&&s2[2]!='D'||s2[2]!='F'){
        cout << "1";
        if(a2[1]==s2[1]+1||a2==s2[1]-1){
            cout <<"1";
        }else{
            cout <<"0";
        }
    }else{
        cout <<"0";
    }



    return 0;
}
