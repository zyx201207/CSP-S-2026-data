#include<bits/stdc++.h>
using namespace std;
int arr[500005],n,m;
int sum[300005];
deque<int>q,p;
bool sss( int c ){
	deque<int>crr;
	crr = p;
	while ( ! crr.empty() ){
		if ( crr.back() == c ){
			return true;
		}
		crr.pop_back();
	}
	return false;
}
int main(){
	freopen ( "card.in" , "r" , stdin );
	freopen ( "card.out" , "w" , stdout );
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ ){
    	cin >> arr[i];
    }
    for ( int i = 1 ; i <= n ; i++ ){
    	while ( ! q.empty() ){
			q.pop_back();
		}
		while ( ! p.empty() ){
			p.pop_back();
		}
    	for ( int j = 1 ; j <= i - 1 ; j++ ){
    		p.push_back ( arr[j] );
    	}
    	for ( int j = i ; j <= n ; j++ ){
    		q.push_back ( arr[j] );
    	}
    	while ( ! q.empty() ){
    		int a = q.front();
    		q.pop_front();
    		if ( sss ( a ) ){
    			q.push_back ( a );
    			while ( p.back() != a ){
    				p.pop_back();
    			}
    			p.pop_back();
    		}else{
    			p.push_back ( a );
    		}
    	}
    	while ( ! p.empty() ){
    		sum[p.back()]++;
    		p.pop_back();
    	}
    }
    for ( int i = 1 ; i <= m ; i++ ){
    	cout << sum[i] << " ";
    }
	return 0;
}
