#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string n1,n2,s1,s2;
    cin >> n1 >> s1 >> n2 >> s2;
    bool s=(n1==n2);
    if (s){
        cout << 1;
    }else{
        cout << 0;
    }
    if (s&&s1[1]==s2[1]&&s1[0]==s2[0]){
        cout << 1;
    }else{
        cout << 0;
    }
    bool t=(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&s1[0]==s2[0]),t2=((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&s1[0]==s2[0]);
    if (s&&(t||t2)){
		cout << 1;
    }else{
        cout << 0;
    }
    if (s&&t){
		//cout << (s1[2]-s2[2]==1) << endl;
		if (s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if (s&&t2){
		cout << 1;
	}else{
		cout << 0;
	}
    //i//f (s1[
    //if (s2[2]>='A'&&s2[2]<='C'&&s1[2]>='A'&&s1[2]<='C'&&(s1[2]-s2[2]==1||s1[2]-s2[2==-1)){
      //  cout << 1;
    //}

    return 0;
}
