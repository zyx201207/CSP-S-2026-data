#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int cnt = 0;
	for(int i = 0; i < 2; ++i){
		if(c1[i] == c2[i]){
			cnt++;
		}
	}
	if(cnt == 2){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	int ans = 0;
	for(int i = 0;i < 2; ++i){
		if(s1[i] == s2[i]){
			ans++;
		}
	}
	if(ans == 2){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
		if(s1[2] == 'A'){
	    	if(s2[2] == 'B'){
		    	cout << "11";
			    return 0;
		    }else if(s2[2] == 'C'){
			    cout << "10";
			    return 0;
		    }else{
			    cout << "00";
			    return 0;
		    }
	    }
	    if(s1[2] == 'B'){
		    if(s2[2] == 'A' or s2[2] == 'C'){
			    cout << "11";
			    return 0;
		    }else{
			cout << "00";
			return 0;
		    }
	    }if(s1[2] == 'C'){
		    if(s2[2] == 'A'){
			    cout << "10";
			    return 0;
		    }else if(s2[2] == 'B'){
			    cout << "11";
			    return 0;
		    }else{
			    cout << "00";
			    return 0;
		    }
	    }
  	    if(s1[2] == 'D'){
	    	if(s2[2] == 'F'){
	    		cout << "11";
	    		return 0;
	    	}else{
	    		cout << "00";
	    		return 0;
	    	}
	    }
    	if(s1[2] == 'F'){
	    	if(s2[2] == 'D'){
		    	cout << "11";
		    	return 0;
		    }else{
		    	cout << "00";
	    		return 0;
	    	}
	    }
} 
