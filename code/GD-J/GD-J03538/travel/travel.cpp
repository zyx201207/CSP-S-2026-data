#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
stringstream ss,sc;
string w;
vector <string> word,words;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
	    cout<<"1";
	}else{
		cout<<"0";
	}
	for(int i=0;i<3;i++){
		//ss.push(s1);
		//sc.push(s2);
		word.push_back(s1);
		words.push_back(s2);
	}
		for(int i=0;i<3;i++){
		if(word[0]==words[0]&&word[1]==words[1]){
			cout<<"1";
		}else{
			cout<<"0";
	}
	}
	return 0;
}
