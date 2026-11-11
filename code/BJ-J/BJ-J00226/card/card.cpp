#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int MAXM = 3e5, MAXN = 5e5;
//int number[MAXM];
stack<int> tmp;
int n, m;
//int cards[MAXN];
//int ans[MAXM];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    vector<int> cards(n+1), number(m+1), ans(m+2), v(n+1);
    for(int i=1;i<=n;i++){
        cin >> cards[i];
    }
    for(int i=1;i<=n;i++){ //轮次
        //cout << "Game" << i << "/" << n << endl;
        if(i!=1){
            //cout << "m";
            for(int i=1;i<=m+1;i++) number[i] = 0;
        }
        //cout << "m" << endl;
        v.resize(0);
        //cout << "m1" << endl;
        for(int j=i;j<=n;j++){
            //cout << "m3" << endl;
            if(number[cards[j]]){
                while(v[v.size()-1]!=cards[j]){
                    number[v[v.size()-1]]--;
                    v.pop_back();
                }

            }else{
                v.push_back(cards[j]);
                number[cards[j]]++;
            }
            //for(int i=1;i<=n;i++) cout << number[i] << " ";
            //cout << endl;
            //cout << "m2" << endl;
            //cout << endl;
        }
        for(int j=1;j<=m;j++){
            ans[j] += (number[j]>0?1:0);
            //cout << "Ans" << j << " ";
        }
        //cout << endl;
    }
    //cout << "answer" << endl;
    //cout << ans.size() << endl;
    for(int i=1;i<=m;i++){
        //cout << i << " ";
        cout << ans[i] << " ";
    }
    //cout << "finished";
    return 0;
}
