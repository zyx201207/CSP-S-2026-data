#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
	
	string s;
	int n, a;
	char c;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a >> c;
		for(int j = 0; j < a; j++){
			s += c;
		} 
	}
    
    int answer = 0;
    int n2 = s.size();
    //cout << n2 << " " << n2/2 << endl;
    for(int i = 0; i < n2/2; i++){
    	if(s[i] != s[n2-1-i]){
    		//cout << i << " " << s[i] << " " << n2+1-i << " " << s[n2-1-i] << endl;
			answer++;
		}
	}
    

    cout << answer;

    fclose(stdin);
    fclose(stdout);


    return 0;
}
