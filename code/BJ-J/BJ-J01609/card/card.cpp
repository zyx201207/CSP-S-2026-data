#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int a[50005];
bool used[30005] = {0};
int number[30005] = {0};
stack<int> table;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;cin>>n,m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    for(int i = 1;i <= n;i++){
        use[30005] = {0};
        for(int j = i;j <= n;j++){
            if(used[a[j]]){
                while(table.top() != a[j]){
                    used[table.top()] = 0;
                    table.pop();
                }
            }else{
                table.push(a[j]);
                used[table.top()] = 1;
            }
        }
        while(!table.empty()){
            number[table.top()]++;
            table.pop();
        }
    }

    for(int i = 1;i <= m;i++){
        cout<<number[m]<<" ";
    }
    return 0;
}
