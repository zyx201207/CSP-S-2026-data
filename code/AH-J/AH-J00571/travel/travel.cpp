#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c[3][4];
    int s[3];
    for(int i=1;i<3;i++){
        cin>>s[i];
        for(int j=1;j<4;i++){
            cin>>c[i][j];
        }
    }
    int a[4],b[4];
    for(int i=1;i<=4;i++){
		a[i]='c[1][i]';
		b[i]='c[2][i]';
	}
	a[1]=='c[1][1]';
	cout<<a[1];
    if(s[1]==s[2]){
        cout<<"1"<<" ";
        if(a[1]==b[1]&&a[2]==b[2]){
            cout<<"1"<<" ";
            if(c[1][3]<=C && c[2][3]<=C){
                cout<<"1"<<" ";
                if(c[1][3]+1==c[2][3] || c[1][3]-1==c[2][3]){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else if(c[1][3]>=D && c[2][3]>=D){
                cout<<"1"<<" ";
                if(c[1][3]+1==c[2][3] || c[1][3]-1==c[2][3]){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            else{
            for(int i=1;i<=2;i++){
                cout<<"0";
                if(i<2){
                    cout<<" ";
            }
        }
        }
        else{
        for(int i=1;i<=3;i++){
            cout<<"0";
            if(i<3){
                cout<<" ";
            }
        }
    }
    else{
        for(int i=1;i<=4;i++){
            cout<<"0";
            if(i<4){
                cout<<" ";
            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
