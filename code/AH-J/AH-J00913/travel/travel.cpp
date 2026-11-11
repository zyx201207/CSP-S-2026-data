#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != "01" && c1 != "16" && c2 != "01" && c2 != "16"){
		if(c1 == c2)cout<<'1';
		else{
		    cout<<"0000";
		    return 0;
		}
	}
	else{
	    cout<<"0000";
	    return 0;
	}
	int si1 = s1[0] -'0' + s1[1] -'0';
	int si2 = s2[0] -'0' + s2[1] -'0';
	if(si1 == si2) cout << '1';
	else{
	    cout << "000";
	    return 0;
	}
	char sj1 = s1[2] ;
	char sj2 = s2[2] ;

	if(sj1 == 'C' && sj2 == 'D' || sj1 == 'D' && sj2 == 'C'){
		cout<<"00";
		return 0;
	}
	else{
		cout<<'1';
	}
	if(sj1 - 1 == sj2 || sj2 - 1 == sj1) cout<<'1';
	else cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
