/*#include <bits/stdc++.h>
using namespace std;
int main(){
    auto tow = [](int num) -> string{
        string result = "";
        while (num){
            result = char(num%2+'0') + result;
            num /= 2;
        }
        return result;
    };
    auto sizeOfTow = [](string num) -> int{
        int sum = 0;
        for (int i = 0 ; i < num.length() ; i++){
            if (num[i]-'0')sum++;
        }
        return sum;
    };

    int n , m;
    cin >> n >> m;
    vector<pair<int , int>>arr(n);
    for (int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a;
        b = sizeOfTow(tow(a));
        arr[i] = {a , b};
        //cout << a << " " << b << endl;
    }
    int Max = -1;
    int index;
    for (int i = 0 ; i < n ; i++){
        if (Max < arr[i].second){
            Max = arr[i].second;
            index = i;
        }
    }
    //cout << Max << endl;
    int num = arr[index].first;
    arr[index].second = -1;
    m--;
    while(m){
        Max = -1;
        for (int i = 0 ; i < n ; i++){
            if (Max < arr[i].second){
                Max = arr[i].second;
                index = i;
            }
        }
        num &= arr[index].first;
        arr[index].second = -1;
        //cout << index << endl;
        m--;
    }
    cout << num;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);

    int n , m;
    cin >> n >> m;
    vector<long>arr(n);
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int num;
    int Max = -1;
    int index[2];
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n ; j++){
            int temp = arr[i]&arr[j];
            if (Max < temp){
                Max = temp;
                index[0] = i ; index[1] = j;
            }
        }
    }
    num = Max;
    arr[index[0]] = 0;
    arr[index[1]] = 0;
    m-=2;
    while (m){
        Max = -1;
        for (int i = 0 ; i < n ; i++){
            int temp = num&arr[i];
            if (Max < temp){
                Max = temp;
                index[0] = i;
            }

        }
        num = Max;
        arr[index[0]] = 0;
        m--;
    }

    cout << num;
    return 0;

}
