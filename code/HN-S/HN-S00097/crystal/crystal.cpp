#include<bits/stdc++.h>
using namespace std;


typedef unsigned long long ull;
typedef pair<int,long long> pil;


int n;
vector<long long> a;
unsigned long long m;


vector<pil> lst;


bool cmp1(pil ca,pil cb){
	if(ca.first == cb.first) return ca.second < cb.second;
	return ca.first > cb.first;
	
}

bool cmp2(pil ca,pil cb){
	return ca.second < cb.second;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	

	for(int i = 1;i <= n;i++){
		long long tmp;
		
		cin >> tmp;
		
		a.push_back(tmp); 
		
		
	}
	sort(a.begin(),a.end());
	int counter = 0;
	long long last = 0;
	for(int i = 0;i <= n;i++){
		if(last != a[i] || i == n){
			if(counter != 0) lst.push_back({counter,last});
			counter = 0;
			last = a[i];
			
		}
		counter++;
		
	}
//	if(counter != 0) lst.push_back({counter,last});
//	
	sort(lst.begin(),lst.end(),cmp1);
	pil start = lst[0];
	
	sort(lst.begin(),lst.end(),cmp2);
	
	counter = 0;
	while(lst[counter].second != start.second) counter++;
	
	int lp = 0,rp = 0;
	int sol = lst.size();
	int plus;
	
	while(m > 0){
		lp--;
		rp++;
		if(lp+counter >= 0 && rp+counter < sol){
			long long dl = start.second - lst[lp+counter].second;
			long long dr = lst[rp+counter].second - start.second;
			if(m >= lst[lp+counter].first * dl && m >= lst[rp+counter].second * dr){
			
			if(lst[lp+counter].first * dr > lst[rp + counter].first * dl) {
				m -= lst[lp+counter].first * dl;
				start.first += lst[lp+counter].first;
				rp--;
			}else{
				m -= lst[rp+counter].first * dr;
				start.first += lst[rp+counter].first;
				start.second = lst[rp+counter].second;
				lp++;
			}
		}else{
			if(dl <= dr){
				plus = m/dl;
				if(plus >= lst[lp+counter].first){
					start.first += lst[lp+counter].first;
					m -= lst[lp+counter].first * dl;
				}else{
					start.first += plus;
					cout << start.first;
					return 0;
						
				}
				plus = m/dr;
				if(plus >= lst[rp+counter].first){
					start.first += lst[rp+counter].first;
					m -= lst[rp+counter].first * dr;
				}else{
					start.first += plus;
					cout << start.first;
					return 0;
						
				}
			}
			
		}
	}else if(lp+counter < 0 && rp+counter < sol){
		long long dr = lst[rp+counter].second - start.second;
		plus = m/dr;
		if(plus >= lst[rp+counter].first){
			start.first += lst[rp+counter].first;
			m -= lst[rp+counter].first * dr;
			start.second = lst[rp+counter].second;
		}else{
			start.first += plus;
			cout << start.first;
			return 0;
						
		}
		
		}
	else if(rp+counter >= sol && lp + counter >= 0){
		long long dl = start.second - lst[lp+counter].second;
		plus = m/dl;
				if(plus > lst[lp+counter].first){
					start.first += lst[lp+counter].first;
					m -= lst[lp+counter].first * dl;
				}else{
					start.first += plus;
					cout << start.first;
					return 0;
						
		}
}else{
	cout << start.first;
	return 0;
	
}
}
		

	cout << start.first;
	return 0;
	}
	
	
