#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8;

int ans[4];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    cout << s1 << s2 << s3 << s4;

    if(s1[1] == s3[1]&&s1[0] == s3[0]){
      ans[0] = 1;
	  if(s2[0] == s4[0]&&s2[1] == s4[1]){
	  	ans[1] = 1;
	  	if((s2[2] - 'A')/3 == (s4[2] - 'A')/3){
	  		ans[2] = 1;
	  		if(int(s2[2]) - int(s4[2]) == 1||int(s2[2]) - int(s4[2]) == -1){
	  			ans[3] = 1;
			  }
		  }
	  }	
	}
	
	for(int i = 0;i < 4;i++){
		cout <<ans[i];
	}
    return 0;
}
