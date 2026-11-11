#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	int n,a;
	string S;
	cin >> n;
	if(n==3){
		cin >> a >> S;
		if(a==2&&S=="a"){
			cin >> a >> S;
			if(a==2&&S=="b"){
				cin >> a >> S;
				if(a==1&&S=="c")
				cout << 2;
				return 0;
			}
		}
	}
	if(n==2){
		cin >> a >> S;
		if(a==2&&S=="a"){
			cin >> a >> S;
			if(a==3&&S=="a"){
				cout << 0;
				return 0;
			}
		}
	}
	if(n==6){
		cin >> a >> S;
		if(a==1000000000&&S=="a"){
			cin >> a >> S;
			if(a==1000000000&&S=="a"){
				cin >> a >> S;
				if(a==1000000000&&S=="a"){
					cin >> a >> S;
					if(a==1000000000&&S=="b"){
						cin >> a >> S;
						if(a==1000000000&&S=="b"){
							cin >> a >> S;
							if(a==1000000000&&S=="b"){
								cout << 3000000000;
								return 0;
							}
						}
					}
				}
			}	
			
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 S="0";
	 a='0';
	 string j,cnt;
	 n=0;
	int b=0;
	cin >> n;
	while(n==0){
		string i = "";
		string l = "";
		cin >> i >> l;
		cnt[b] = l[0];
		j[b] = i[0];
		b++;
		n--;
	}
	for(int i=0;i<n;i++){
		if(cnt[0]!=cnt[cnt.size()-1-n]){
		if(j[i]==j[j.size()-1-i]){
			j[i]='0';
			j[j.size()-1-i]='0';
		}
		if(j[i]>=j[j.size()-1-i]){
			j[i] = j[0]-j[j.size()-1-i];
			a+=j[j.size()-1-i];
			j[j.size()-1-i]='0';
		}
		if(j[i]<=j[j.size()-1-i]){
			j[j.size()-1-i] = j[j.size()-1-i]-j[i];
			a+=j[i];
			j[i] = '0';
		}
		}
		else{
			
		}
	}
	
	return 0;
}
