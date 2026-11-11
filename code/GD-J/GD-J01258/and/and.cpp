#include <bits/stdc++.h>
using namespace std;



int a[200010];
int ma[200010];

int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
	

    int n, m;
    long long answer;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
	}

    if(m == n){
    	answer = a[0];
    	for(int i = 1; i < n; i++){
    		answer = answer and a[i];	
		}
	} else if (m == 1){
		answer = -1;
		for(int i = 0; i < n; i++){
			if(answer < a[i]) answer = a[i];
		}
	} else if(m == 2){
		answer = 0;
		for(int i = 0; i < n-1; i++){
			for(int j = 1; j < n; j++){
				int x = a[i], y = a[j];
				//cout << endl << x << " " << y << " " << endl;
				//cout << x and y;
				if(x and y >= answer) {
					answer = x and y;
				}
			}
		}
	}


	cout << answer;
    fclose(stdin);
    fclose(stdout);


    return 0;
}
